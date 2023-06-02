#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    vector<vector<int>> sq;
    int r, c, hr;
};

bool comp(node *p1, node *p2)
{
    if (p1->hr < p2->hr)
    {
        return true;
    }
    return false;
}

void EightSquare(vector<vector<int>> start, vector<vector<int>> goal, vector<node *> &ol, vector<node *> &cl, int r, int c)
{
    cout<<"Heuristic value "<<ol.front()->hr<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ol.front()->sq[i][j] << " | ";
        }
        cout << "\n";
    }
    cout<<"\n\n";

    if (ol.front()->sq == goal)
    {
        exit(0);
    }

    if (c + 1 < 3)
    {
        vector<vector<int>> test = ol.front()->sq;
        swap(test[r][c], test[r][c + 1]);
        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (test[i][j] != goal[i][j])
                {
                    count++;
                }
            }
        }
        node *newnode = new node();
        newnode->sq = test;
        newnode->hr = count;
        newnode->c = c + 1;
        newnode->r = r;

        ol.push_back(newnode);
    }
    if (c - 1 >= 0)
    {
        vector<vector<int>> test = ol.front()->sq;
        swap(test[r][c], test[r][c - 1]);
        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (test[i][j] != goal[i][j])
                {
                    count++;
                }
            }
        }
        node *newnode = new node();
        newnode->sq = test;
        newnode->hr = count;
        newnode->c = c - 1;
        newnode->r = r;

        ol.push_back(newnode);
    }

    if (r + 1 < 3)
    {
        vector<vector<int>> test = ol.front()->sq;
        swap(test[r][c], test[r + 1][c]);
        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (test[i][j] != goal[i][j])
                {
                    count++;
                }
            }
        }
        node *newnode = new node();
        newnode->sq = test;
        newnode->hr = count;
        newnode->c = c;
        newnode->r = r + 1;

        ol.push_back(newnode);
    }
    if (r - 1 >= 0)
    {
        vector<vector<int>> test = ol.front()->sq;
        swap(test[r][c], test[r - 1][c]);
        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (test[i][j] != goal[i][j])
                {
                    count++;
                }
            }
        }
        node *newnode = new node();
        newnode->sq = test;
        newnode->hr = count;
        newnode->c = c;
        newnode->r = r - 1;

        ol.push_back(newnode);
    }

    cl.push_back(ol.front());
    ol.erase(ol.begin());

    while (!ol.empty())
    {
        sort(ol.begin(), ol.end(), comp);
        EightSquare(ol.front()->sq, goal, ol, cl, ol.front()->r, ol.front()->c);
    }
}

int main()
{
    vector<node *> ol;
    vector<node *> cl;
    int count = 0;
    vector<vector<int>> start = {
        {1, 2, 3},
        {5, 6, 4},
        {7, 8, 0}};

    vector<vector<int>> goal = {
        {2, 0, 3},
        {1, 5, 4},
        {7, 6, 8}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (start[i][j] != goal[i][j])
            {
                count++;
            }
        }
    }

    int r = 2, c = 2;
    node *newnode = new node();
    newnode->sq = start;
    newnode->hr = count;
    newnode->r = r;
    newnode->c = c;

    ol.push_back(newnode);

    EightSquare(start, goal, ol, cl, r, c);
    return 0;
}