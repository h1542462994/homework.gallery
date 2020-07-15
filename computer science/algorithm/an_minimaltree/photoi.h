//
// Created by t1542 on 2020/5/14.
//
#pragma once
#include "side.h"
#include "mat.h"
#include "find.h"
#include <vector>
#include <queue>

using namespace std;

typedef priority_queue<side<int>, vector<side<int>>, greater<>> pg_greater;

class photoi{
public:
    photoi(mat<int> m){
        init(m, size, sides);
    }
    photoi(){
        size = 0;
    }

    void get_prim(mat<int>& m, int& length){
        // 初始化点
        vector<int> points = {0};
        vector<side<int>> select_sides;
        // 使用prim扩展节点
        while(points.size() < size){
            side<int> s(0,0);
            if(try_get_min_through_side(points, s)){
                points.push_back(get_o_point(points, s));
                select_sides.push_back(s);
            }
        }

        to_mat(size, select_sides, m,length);
    }
    void get_kruskal(mat<int>& m, int& length){
        // 当前边的点集合
        vector<vector<int>> points;
        // 当前选择的边
        vector<side<int>> select_sides;
        int p_count = 0;

        // 确保每次选择边的长度最小
        pg_greater pg;
        for(auto side:sides){
            pg.push(side);
        }

        // 如果没有涵盖所有点或者有剩余边
        while((p_count < size || points.size() > 1) && !pg.empty()){
            auto side = pg.top();
            pg.pop();

            // condition1: 所有点都在已有的点集外。
            int index1 = get_index_of_point(points, side.start);
            int index2 = get_index_of_point(points, side.end);

            if(index1 == -1 && index2 == -1){
                p_count += 2;
                points.push_back({side.start, side.end});
                select_sides.push_back(side);
            } else if (index1 == -1) { // condition2: 其中一点在点集内，另外一点在点集外。
                p_count += 1;
                points[index2].push_back(side.start);
                select_sides.push_back(side);
            } else if (index2 == -1) { // condition2:;
                p_count += 1;
                points[index1].push_back(side.end);
                select_sides.push_back(side);
            } else if (index1 != index2 ){ // condition: 跨越，此时将合并点集
                combine_point(points, index1, index2);
                select_sides.push_back(side);
            }

        }

        //cout << points.size() << endl;
        to_mat(size, select_sides, m, length);
    }

    void to_mat(int _size, const vector<side<int>>& _sides,mat<int>& m, int& length){
        // 转化为标准输出
        m = mat<int>(size, size);
        m.to_default();
        length = 0;

        for(auto s: _sides){
            m.at(s.start, s.end) = s.length;
            m.at(s.end, s.start) = s.length;
            length += s.length;
        }
    }
private:
    int size;
    vector<side<int>> sides;

    /**
     * 从当前选中的点中找到最小的一条边，满足其中一个节点在内部，另外一个节点在外部。
     * @param points
     */
    bool try_get_min_through_side(const vector<int>& points, side<int>& _side){
        pg_greater pg;
        for(auto side: sides){
            if(get_type_of_side(points, side) == 1){
                pg.push(side);
            }
        }
        if(pg.empty())
            return false;
        else{
            _side = pg.top();
            return true;
        }
    }

    static int get_type_of_side(const vector<int>& points, side<int> side){
        if(contains(points, side.start) && contains(points, side.end)){
            return 0;
        } else if(!contains(points, side.start) && !contains(points, side.end)){
            return 2;
        } else {
            return 1;
        }
    }

    static int get_index_of_point(const vector<vector<int>>& points, int point){
        int _size = points.size();
        for(int i = 0; i < _size; ++i){
            if(contains(points[i],point)){
                return i;
            }
        }
        return -1;
    }

    static int get_o_point(const vector<int>& points, side<int> side){
        if(contains(points, side.start))
            return side.end;
        return side.start;
    }

    static void combine_point(vector<vector<int>>& points, int index1, int index2){
        int i = 0;
        vector<vector<int>> new_vector;

        vector<int> combined;
        for (const auto& p: points) {
            if(index1 != i && index2 != i){
                new_vector.push_back(p);
            } else {
                for (auto p2: p) {
                    combined.push_back(p2);
                }
            }
            ++i;
        }

        new_vector.push_back(combined);
        points = new_vector;
    }

    static void init(mat<int>& m, int& _size, vector<side<int>>& _sides){
        _size = m.row_count();
        for(int i = 0; i < _size - 1 ; ++i){
            for(int j = i+1; j < _size; ++ j){
                if(m.at(i,j) != 0){ //存在边的情况
                    side<int> s(i,j, m.at(i,j));
                    _sides.push_back(s);
                }
            }
        }
    }
};
