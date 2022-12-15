#include <iostream>
#include <vector>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	vector<pair<int, int>> lst;
	int t_case, truck_size, trash_num, dist, trash, cur_size, cur_dist, tot_dist;

    fastio;
	cin >> t_case;
	while (t_case--)
	{
		cin >> truck_size >> trash_num;
		lst.clear();
		for (int i = 0; i < trash_num; i++)
		{
			cin >> dist >> trash;
			lst.push_back({dist, trash});
		}
		tot_dist = 0;
		cur_dist = 0;
		cur_size = 0;
		for (int i = 0; i < trash_num; i++)
		{
			tot_dist += lst[i].first - cur_dist;
			cur_dist = lst[i].first;
			cur_size += lst[i].second;
			if (cur_size > truck_size)
			{
				tot_dist += lst[i].first * 2;
				cur_size = lst[i].second;
			}
			else if (cur_size == truck_size && i != trash_num - 1)
			{
				tot_dist += lst[i].first * 2;
				cur_size = 0;
			}
		}
		cout << tot_dist + lst[trash_num - 1].first << "\n";
	}
	return (0);
}