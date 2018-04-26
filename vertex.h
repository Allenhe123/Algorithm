#ifndef VERTEX_H
#define VERTEX_H

struct vertex
{
	int x;
	int y;
	int val;

	vertex(): x(0), y(0), val(0) {}
	vertex(int xi, int yi, int v): x(xi), y(yi), val(v) {}
};

#endif