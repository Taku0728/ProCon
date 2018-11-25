#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

using namespace std;
using ll = long long;

// 都市の情報を格納するクラス
class ipy
{
public:
	// i:都市番号（全体）
	// p:県番号
	// y:誕生年
	int i, p, y;
	// コンストラクタ
	ipy(int ii, int pp, int yy) {
		i = ii;
		p = pp;
		y = yy;
	}
};

int main() {
	// すべての都市の情報を格納するipyのベクター
	vector<ipy> i_p_y;
	int N, M;
	cin >> N >> M;
	// すべての都市の情報を受け取り、i_p_yに格納
	for (int i = 1; i != M + 1; ++i) {
		int p, y;
		cin >> p >> y;
		i_p_y.push_back(ipy(i, p, y));
	}
	// i_p_yを都市の誕生順にソート
	sort(begin(i_p_y), end(i_p_y), [](ipy l, ipy r){ return l.y < r.y; });
	// すべての県の都市の数をカウントベクター	
	vector<int> p_count(100001, 1);
	// 出力するidの2つの整数を格納するベクター
	vector<pair<int, int> > out(M + 1);
	// すべての都市についてループ
	for (int i = 0; i != M; ++i) {
		// 全体のi_p_y[i].i番目の都市はi_p_y[i].p県のp_count[i_p_y[i].p番目の都市
		out[i_p_y[i].i] = pair<int, int>(i_p_y[i].p, p_count[i_p_y[i].p]);
		// その県の都市のカウントを増やす
		++p_count[i_p_y[i].p];
	}
	// ２つの数をそれぞれ6桁の0埋めをして出力
	for (int i = 1; i < M + 1; ++i) {
		cout << std::setfill('0') << std::setw(6) << out[i].first;
		cout << std::setfill('0') << std::setw(6) << out[i].second;
		cout << endl;
	}
}

