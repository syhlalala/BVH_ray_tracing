#ifndef __BVHTREE_H__
#define __BVHTREE_H__

#include "triangle.h"
#include "pnt.h"
#include "line.h"

#include <cstdlib>

class BVHBox {
public:
	Vector2 x_range, y_range, z_range;
	int count;

	void calc_box(Triangle *t, int n);
	void clear();
	bool is_empty();
	void add(const Triangle& t);
	void add(const Vector3& p);
	float get_surface_area();
	void merge(const BVHBox& b);

	//判交
	bool intersect(const Line3& line, float& min_intersect) const;
private:
};

class BVHTree {
public:
	//用于存储这棵树表示的所有三角形
	Triangle *triangles;
	
	//包围盒
	//Vector2 x_range, y_range, z_range;
	BVHBox box;

	//左右儿子
	BVHTree *left_son, *right_son;
	
	//表示了这个子树下面区间[l, r]的三角形
	int l, r;
	
	//判断是否是叶子
	bool is_leaf() const;
	//建树
	void create_tree(int n, Triangle *triangles = NULL);
	//求交
	bool intersect(const Line3& line, Vector3& result, int& index);
	bool intersect(const Line3& line, Vector4& result, int& index);

	static int CCOUNT;

	//析构
	~BVHTree();

private:
	
	void _create(int l, int r);
	int _get_diff(const Triangle& t, float block_length, int type);
	float _get_block_length(int type);


	static const int BLOCK_SIZE; 
	static BVHBox *_piece_box;
};

#endif // __BVHTREE_H__
