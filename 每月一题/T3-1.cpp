#include <iostream>
using namespace std;

int A, B;
int *ans;
bool **pokers;
pair<int, int> card_in_hand[5];
pair<int, int> sorted_cards[5];

bool is_flush();
bool is_straight();
// 升序排列
void mySort() {
    for (int i = 0; i < 5; i++)
        sorted_cards[i] = card_in_hand[i];
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            if (sorted_cards[i].first < sorted_cards[j].first)
                swap(sorted_cards[i], sorted_cards[j]);
        }
    }
}
// 同花顺
bool is_straight_flush() {
    return is_flush() && is_straight();
}
// 炸弹
bool is_bomb() {
    if (sorted_cards[0].first == sorted_cards[3].first || sorted_cards[1].first == sorted_cards[4].first)
        return true;
    return false;
}
// 三带二
bool is_three_with_two() {
    if ((sorted_cards[0].first == sorted_cards[1].first && sorted_cards[2].first == sorted_cards[4].first) || (sorted_cards[0].first == sorted_cards[2].first && sorted_cards[3].first == sorted_cards[4].first))
        return true;
    return false;
}
// 同花
bool is_flush() {
    int tag = sorted_cards[0].second;
    for (int i = 1; i < 5; i++)
        if (tag != sorted_cards[i].second)
            return false;
    return true;
}
// 顺子
bool is_straight() {
    for (int i = 1; i < 5; i++) {
        if (sorted_cards[i].first - sorted_cards[i - 1].first != 1)
            return false;
    }
    return true;
}
// 三条
bool is_triple() {
    if (sorted_cards[0].first == sorted_cards[2].first || sorted_cards[1].first == sorted_cards[3].first || sorted_cards[2].first == sorted_cards[4].first)
        return true;
    return false;
}
// 双对
bool is_two_double() {
    if ( (sorted_cards[0].first == sorted_cards[1].first && sorted_cards[2].first == sorted_cards[3].first) || (sorted_cards[1].first == sorted_cards[2].first && sorted_cards[3].first == sorted_cards[4].first) || (sorted_cards[0].first == sorted_cards[1].first && sorted_cards[3].first == sorted_cards[4].first) )
        return true;
    return false;
}
// 对子
bool is_double() {
    if ( sorted_cards[0].first == sorted_cards[1].first || sorted_cards[1].first == sorted_cards[2].first || sorted_cards[2].first == sorted_cards[3].first || sorted_cards[3].first == sorted_cards[4].first )
        return true;
    return false;
}

void backtrack(int left) {
    if (left == 0) {
        mySort();
        if (is_straight_flush())
            ans[0]++;
        else if (is_bomb())
            ans[1]++;
        else if (is_three_with_two())
            ans[2]++;
        else if (is_flush())
            ans[3]++;
        else if (is_straight())
            ans[4]++;
        else if (is_triple())
            ans[5]++;
        else if (is_two_double())
            ans[6]++;
        else if (is_double())
            ans[7]++;
        else
            ans[8]++;
        return;
    }

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            if (pokers[i][j]) {
                pokers[i][j] = false;
                card_in_hand[5 - left] = make_pair(i, j);
                backtrack(left - 1);
                pokers[i][j] = true;
            }
        }
    }
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int a1, b1, a2, b2;
    cin >> A >> B >> a1 >> b1 >> a2 >> b2;
    pokers = new bool*[A];
    for (int i = 0; i < A; i++)
        pokers[i] = new bool[B];
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            pokers[i][j] = true;
    ans = new int[9];
    for (int i = 0; i < 8; i++)
        ans[i] = 0;

    pokers[a1][b1] = false;
    pokers[a2][b2] = false;
    card_in_hand[0] = make_pair(a1, b1);
    card_in_hand[1] = make_pair(a2, b2);
    backtrack(3);
    for (int i = 0; i < 9; i++) {
        cout << ans[i] / 6 << ' ';
    }
    cout << endl;
    for (int i = 0; i < A; i++)
        delete[] pokers[i];
    delete[] pokers;
    delete[] ans;

    return 0;
}