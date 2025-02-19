//2017029870_신호중

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

class edge
{
public:
	int vertexA;
	int vertexB;
	int wht;
	bool operator < (const edge &edges) const
	{
		if ( wht != edges.wht )
			return wht > edges.wht;
		else if ( vertexA != edges.vertexA )
			return vertexA > edges.vertexA;
		else
			return vertexB > edges.vertexB;
	}
} edges[500000];

priority_queue <edge> pq;
priority_queue <edge> path;

struct _vertex;
typedef struct _vertex vertex;

struct _vertex
{
	vertex* pnt;
	int rnk;
	int val;
};

void make_set(vertex* v, int val)
{
	v->pnt = v;
	v->rnk = 0;
	v->val = val;
}

vertex* find(vertex* v)
{
	if ( v != v->pnt ) v->pnt = find(v->pnt);
	return v->pnt;
}

void link(vertex* x, vertex* y)
{
	if ( x->rnk > y->rnk )
		y->pnt = x;
	else
	{
		x->pnt = y;
		if ( x->rnk == y->rnk ) y->rnk += 1;
	}
}

void union_set(vertex* x, vertex* y)
{
	link(find(x), find(y));
}

int main()
{
	int i;
	int num_vertex;
	int vertexA, vertexB, wht;

	scanf("%d", &num_vertex);
	vertex* graph = new vertex[num_vertex + 1];

	i = 0;
	while ( scanf("%d %d %d", &vertexA, &vertexB, &wht) != EOF )
	{
		if ( vertexA < vertexB )
		{
			edges[i].vertexA = vertexA;
			edges[i].vertexB = vertexB;
		}
		else
		{
			edges[i].vertexA = vertexB;
			edges[i].vertexB = vertexA;
		}

		edges[i].wht = wht;
		pq.push(edges[i]);
		i++;
	}

	for ( i = 1; i <= num_vertex; i++ )
		make_set(&graph[i], i);

	while ( !pq.empty() )
	{
		if ( find(&graph[pq.top().vertexA]) != find(&graph[pq.top().vertexB]) )
		{
			union_set(&graph[pq.top().vertexA], &graph[pq.top().vertexB]);
			path.push(pq.top());
		}
		pq.pop();
	}

	printf("%d\n", num_vertex - 1);
	while ( !path.empty() )
	{
		printf("%d %d %d\n", path.top().vertexA, path.top().vertexB, path.top().wht);
		path.pop();
	}

	delete[] graph;
	return 0;
}