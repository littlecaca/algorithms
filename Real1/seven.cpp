#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// 记录x轴上的阴影段的有序集合
static map<double, double> record;

// 保存线段的类
struct Line
{
	int xl;
	int xr;
	int y;

	Line(int x, int y_, int l) : xl(x), xr(x + l), y(y_) {}
};

bool operator<(const Line &lhs, const Line& rhs)
{
	return lhs.y < rhs.y;
}

// 保存Line的vector
static vector<Line> lines;

// 计算由(x, y)和(sx, sy)确定的点与x轴的交点的横坐标
constexpr double cal(double x, double y, double sx, double sy)
{
	return x - y * (x - sx) / (y - sy);
}

// 将新的阴影段加入集合record，并返回是否没有被阴影段覆盖
bool addLine(double xl, double xr)
{
	bool res = true;


	auto edge_left = record.upper_bound(xl);
	auto edge_right = record.upper_bound(xr);


	if (edge_left != record.begin() && xr <= (--edge_left)++->second)
		res = false;
	else
	{
		// 没有重合，则加入阴影段集合
		if (edge_left != record.begin())
		{
			--edge_left;
			if (xl <= edge_left->second) xl = edge_left->first;
			else ++edge_left;
		}
		if (edge_right != record.begin())
		{
			--edge_right;
			if (xr <= edge_right->second) xr = edge_right->second;
			++edge_right;
		}
		record.erase(edge_left, edge_right);
		record.insert({xl, xr});
	}

	return res;
}

int main()
{
	int ans = 0;

	// 读取太阳点和线段数量
	int m, sx, sy;
	cin >> m >> sx >> sy;
	while (m--)
	{
		int x, y, l;
		cin >> x >> y >> l;
		lines.emplace_back(x, y, l);
	}

	// 将线段从高到低排序
	sort(lines.rbegin(), lines.rend());

	for (auto &li : lines)
	{
		// 计算在x轴上的阴影起始位置
		double xl = cal(li.xl, li.y, sx, sy);
		double xr = cal(li.xr, li.y, sx, sy);
		if (addLine(xl, xr)) ++ans;
	}
	cout << ans << endl;
	return 0;
}