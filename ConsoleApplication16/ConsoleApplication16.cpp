#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addRow(vector<vector<string>>& matrix, const vector<string>& newRow, int position) {
    if (position >= 0 && position <= matrix.size()) {
        matrix.insert(matrix.begin() + position, newRow);
    }
}

void deleteRow(vector<vector<string>>& matrix, int rowIndex) {
    if (rowIndex >= 0 && rowIndex < matrix.size()) {
        matrix.erase(matrix.begin() + rowIndex);
    }
}

vector<vector<int>> oneDToTwoD(const vector<int>& arr, int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows * cols; i++) {
        matrix[i / cols][i % cols] = arr[i];
    }
    return matrix;
}

vector<int> twoDToOneD(const vector<vector<int>>& matrix) {
    vector<int> arr;
    for (const auto& row : matrix) {
        arr.insert(arr.end(), row.begin(), row.end());
    }
    return arr;
}

class ContactList {
    vector<vector<string>> contacts;

public:
    void addContact(const string& name, const string& phone) {
        contacts.push_back({ name, phone });
    }

    string searchByName(const string& name) {
        for (const auto& contact : contacts) {
            if (contact[0] == name) return contact[1];
        }
        return "Не знайдено";
    }

    string searchByPhone(const string& phone) {
        for (const auto& contact : contacts) {
            if (contact[1] == phone) return contact[0];
        }
        return "Не знайдено";
    }

    void updateContact(const string& name, const string& newPhone) {
        for (auto& contact : contacts) {
            if (contact[0] == name) {
                contact[1] = newPhone;
                return;
            }
        }
    }
};

int main() {
    vector<vector<string>> matrix = { {"A", "B"}, {"C", "D"} };
    addRow(matrix, { "X", "Y" }, 1);
    deleteRow(matrix, 0);

    vector<int> oneDArray = { 1, 2, 3, 4, 5, 6 };
    vector<vector<int>> twoDArray = oneDToTwoD(oneDArray, 2, 3);
    vector<int> backToOneD = twoDToOneD(twoDArray);

    ContactList contacts;
    contacts.addContact("Іван", "123456");
    contacts.addContact("Марія", "654321");
    cout << contacts.searchByName("Іван") << endl;
    cout << contacts.searchByPhone("654321") << endl;
    contacts.updateContact("Іван", "111111");

    return 0;
}
