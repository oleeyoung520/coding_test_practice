#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmpSameGenre(tuple<int, int> t1, tuple<int, int> t2) {
    if (get<1>(t1) == get<1>(t2)) {
        return get<0>(t1) < get<0>(t2);
    } else {
        return get<1>(t1) > get<1>(t2);
    }
}

bool cmp(tuple<int, string> t1, tuple<int, string> t2) {
    return get<0>(t1) > get<0>(t2);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<tuple<int, int>>> music;
    for (int i = 0; i < int(genres.size()); i++) {
        music[genres[i]].push_back(make_pair(i, plays[i]));
    }
    vector<tuple<int, string>> forSort;
    for (auto it = music.begin(); it != music.end(); it++) {
        int sum = 0;
        for (int i = 0; i < int((it->second).size()); i++) {
            sum += get<1>((it->second)[i]);
        }
        forSort.push_back(make_pair(sum, it->first));
        sort((it->second).begin(), (it->second).end(), cmpSameGenre);
    }
    sort(forSort.begin(), forSort.end(), cmp);
    for (int i = 0; i < int(forSort.size()); i++) {
        string genre = get<1>(forSort[i]);
        int genreCnt = int(music[genre].size());
        if (genreCnt == 1) {
            answer.push_back(get<0>(music[genre][0]));
        } else if (genreCnt >= 2) {
            answer.push_back(get<0>(music[genre][0]));
            answer.push_back(get<0>(music[genre][1]));
        }
    }


    return answer;
}