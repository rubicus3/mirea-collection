#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long int compare_count = 0;

// Прямой перебор   
void find_combinations(const vector<int>& coins, int S, int current_sum, int current_count, int index, vector<int>& current_combination, int& min_coins, vector<int>& best_combination) {
    
    compare_count += 2;
    if (current_sum == S) {
        if (current_count < min_coins) {
            min_coins = current_count;
            best_combination = current_combination;
        }
        return;
    }

    compare_count += 2;
    if (current_sum > S || index == coins.size()) {
        return;
    }

    int coin = coins[index];
    int max_use = (S - current_sum) / coin;
    for (int i = 0; i <= max_use; ++i) {
        compare_count += 1;

        for (int j = 0; j < i; ++j) {
            compare_count += 1;
            current_combination.push_back(coin);
        }
        find_combinations(coins, S, current_sum + i * coin, current_count + i, index + 1, current_combination, min_coins, best_combination);
        for (int j = 0; j < i; ++j) {
            compare_count += 1;
            currentet_combination.pop_back();
        }
    }
}

pair<int, vector<int>> find_min_coins_bruteforce(const vector<int>& coins, int S) {
    int min_coins = INT_MAX;
    vector<int> best_combination;
    vector<int> current_combination;
    compare_count = 0;

    find_combinations(coins, S, 0, 0, 0, current_combination, min_coins, best_combination);

    return {min_coins, best_combination};
}

// Жадный алгоритм
vector<int> find_min_coins_greedy(const vector<int>& coins, int S) {
    vector<int> sorted_coins = coins;
    sort(sorted_coins.rbegin(), sorted_coins.rend());
    compare_count = 0;

    vector<int> combination;

    for (int coin : sorted_coins) {
        while (S >= coin) {
            compare_count += 1;
            S -= coin;
            combination.push_back(coin);
        }
    }

    return  combination;
}

int main() {
    vector<int> coins = {1, 11, 18};
    int S = 63;
    cout << "Необходимая сумма: " << S << endl;

    // Прямой перебор
    auto result_bruteforce = find_min_coins_bruteforce(coins, S);
    int min_coins_bruteforce = result_bruteforce.first;
    vector<int> combination_bruteforce = result_bruteforce.second;

    cout << "Прямой перебор:" << endl;
    cout << "Количество монет: " << min_coins_bruteforce << endl;
    cout << "Комбинация: ";
    for (int coin : combination_bruteforce) {
        cout << coin << " ";
    }
    cout << endl << "Количество сравнений: " << compare_count;
    cout << endl;

    // Жадный алгоритм
    auto result_greedy = find_min_coins_greedy(coins, S);
    int min_coins_greedy = result_greedy.size();

    cout << "Жадный алгоритм:" << endl;
    cout << "Количество монет: " << min_coins_greedy << endl;
    cout << "Комбинация: ";
    for (int coin : result_greedy) {
        cout << coin << " ";
    }
    cout << endl << "Количество сравнений: " << compare_count;
    cout << endl;

    return 0;
}
