/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>

//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

class Tree
{
	private:
		const static int RANGE = 131072;
		int data[2 * RANGE];

	public:
		Tree(void);
		inline void propagate(void);
		inline void set(const int &where, const int &what);
		inline int get(const int &where) const;
		inline void update(const int &where, const int &value = 1);
		inline int lowerBound(int value) const;
};

int queues,
	queries,
	queue[131072],
	idToQueue[131072],
	queueToId[131072],
	action,
	val,
	id;
Tree tree;

inline bool queueCompare(const int &a, const int &b)
{
	return queue[a] < queue[b];
}

inline static int MAX(const int &a, const int &b){return a>b?a:b;}

int main(void)
{
	scanf("%d %d", &queues, &queries);
	for(int q = 0; q < queues; ++ q)
	{
		scanf("%d", &queue[q]);
		idToQueue[q] = q;
	}

	std::sort(idToQueue, idToQueue + queues, queueCompare);
	for(int i = 0; i < queues; ++ i)
		queueToId[idToQueue[i]] = i;

	tree.set(0, queue[idToQueue[0]]);
	for(int q = 1; q < queues; ++ q)
		tree.set(q, queue[idToQueue[q]] - queue[idToQueue[q - 1]]);

	tree.propagate();
	for(int q = 0; q < queries; ++ q)
	{
		scanf("%d %d", &action, &val);
		switch(action)
		{
			case 1:
				-- val;
				id = tree.lowerBound(tree.get(queueToId[val]) + 1) - 1;
				if(id != queueToId[val])
				{
					std::swap(idToQueue[id], idToQueue[queueToId[val]]);
					std::swap(queueToId[val], queueToId[idToQueue[queueToId[val]]]);
				}

				tree.update(queueToId[val]);
				if(queueToId[val] + 1 < queues)
					tree.update(queueToId[val] + 1, -1);

				break;

			case 2:
				printf("%d\n", queues - tree.lowerBound(val));
				break;

			case 3:
				tree.update(tree.lowerBound(val), -1);
				break;
		}
	}

	return 0;
}

Tree::Tree(void)
{
	for(int r = 0; r < this->RANGE; ++ r)
		this->data[r] = 0;

	return;
}

inline void Tree::propagate(void)
{
	for(int r = this->RANGE - 1; r; -- r)
		this->data[r] = MAX(this->data[r * 2] + this->data[r * 2 + 1], 0);

	return;
}

inline void Tree::set(const int &where, const int &what)
{
	this->data[this->RANGE + where] = what;

	return;
}

inline int Tree::get(const int &where) const
{
	int start = 0,
		size = this->RANGE,
		pos = 1,
		result = 0;

	while(true)
	{
		if(start + size - 1 > where)
		{
			size /= 2;
			pos *= 2;
		}

		else if(start + size - 1 < where)
		{
			result += this->data[pos];
			pos += 1;
			start += size;
		}

		else
			return result + this->data[pos];
	}

	return result;
}

inline void Tree::update(const int &where, const int &value)
{
	int pos = this->RANGE + where;
	this->data[pos] = MAX(this->data[pos] + value, 0);
	pos /= 2;
	while(pos)
	{
		this->data[pos] = MAX(this->data[pos * 2] + this->data[pos * 2 + 1], 0);
		pos /= 2;
	}

	return;
}

inline int Tree::lowerBound(int value) const
{
	bool add = false;
	if(value > this->data[1])
	{
		value = this->data[1];
		add = true;
	}

	int pos = 1;
	while(pos < this->RANGE)
	{
		if(this->data[pos * 2] < value)
		{
			value -= this->data[pos * 2];
			pos = pos * 2 + 1;
		}

		else
			pos *= 2;
	}

	return pos - this->RANGE + add;
}
