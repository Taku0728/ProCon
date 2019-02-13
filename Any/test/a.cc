#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	vector< vector<string> > data;
	ifstream ifs("a");
	if (!ifs) {
		cout << "NO" << endl;
	}
	string str;
	while(getline(ifs, str)) {
		vector<string> v;
		stringstream stream(str);
		string buf;
		while(getline(stream, buf, ' ')) {
			v.push_back(buf);
		}
		data.push_back(v);
	}

	for (auto i : data) {
		for (auto j : i) {
			cout << j << ",";
		}
		cout << endl;
	}

	ifs.close();
}
