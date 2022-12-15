#include <iostream>
#include <cmath>
#include <memory>
#include <fstream>
#include <experimental/random>

bool get_random_bool() {
    return std::experimental::randint(100, 999) % 2;
}

class DoKakVMatritse {
public:
    DoKakVMatritse(int n, int amount) {
        if ((n < 0) || (amount < 0)) {
            throw std::invalid_argument( "����� ������ ��� ���������� ����� ������ ����" );
        }
        len = n;
        amount_of_rows = amount;
        translator = std::make_unique<bool[]>(8);
        now_row = std::make_unique<bool[]>(n);
        for (int i = 0; i < 8; ++i) {
            translator[i] = get_random_bool();
        }
        for (int i = 0; i < n; ++i) {
            now_row[i] = get_random_bool();
        }
    }

    DoKakVMatritse() {
        std::ifstream in("data.txt");
        if (in.is_open()) {
            std::string line;
            std::getline(in, line);
            for (auto elem : line) {
                if (!std::isdigit(elem)) {
                    throw std::invalid_argument("���������� ��� ����� ������");
                }
            }
            try {
                len = std::stoi(line);
            } catch(...) {
                throw std::invalid_argument("����� ������ ����� ��� int");
            }
            std::getline(in, line);
            for (auto elem : line) {
                if (!std::isdigit(elem)) {
                    throw std::invalid_argument("���������� ��� ����� �����������");
                }
            }
            try {
                amount_of_rows = std::stoi(line);
            } catch(...) {
                throw std::invalid_argument("���������� ����� ����� ��� int");
            }
            if ((len < 0) || (amount_of_rows < 0)) {
                throw std::invalid_argument( "����� ������ ��� ���������� ����� ������ ����" );
            }
            std::getline(in, line);
            now_row = std::make_unique<bool[]>(len);
            for (int i = 0; i < 2 * len - 1; i += 2) {
                try {
                    if ((line[i] < '0') || (line[i] > '1')) {
                        throw std::invalid_argument("");
                    }
                    now_row[i / 2] = line[i] - '0';
                } catch(...) {
                    throw std::invalid_argument("� ��������� ������ ������������ ������");
                }
            }
            if (line.size() > 2 * len - 1) {
                throw std::invalid_argument("������� ����� �������� � ��������� ������");
            }
            std::getline(in, line);
            translator = std::make_unique<bool[]>(8);
            for (int i = 0; i < 15; i += 2) {
                try {
                    if ((line[i] < '0') || (line[i] > '1')) {
                        throw std::invalid_argument("");
                    }
                    translator[i / 2] = line[i] - '0';
                } catch(...) {
                    throw std::invalid_argument("� ������-����������� ������������ ������");
                }
            }
            if (line.size() > 15) {
                throw std::invalid_argument("������� ����� �������� � ������-�����������");
            }
        } else {
            throw std::runtime_error("���� �� ��������");
        }
    }

    void DoKrasivo() {
        for (int i = 0; i < 8; ++i) {
            std::cout << translator[i] << ' ';
        }
        std::cout << '\n';
        for (int i = 0; i < amount_of_rows; ++i) {
            for (int j = 0; j < len; ++j) {
                std::cout << now_row[j] << ' ';
            }
            std::cout << '\n';
            compute_next_row();
        }
    }

private:
    std::unique_ptr<bool[]> now_row;
    std::unique_ptr<bool[]> translator;
    int amount_of_rows = 0;
    int len = 0;


    void compute_next_row() {
        auto new_row = std::make_unique<bool[]>(len);
        for (int i = 0; i < len; ++i) {
            int ids = now_row[(i + len - 1) % len] + 2 * now_row[i] + 4 * now_row[(i + 1) % len];
            new_row[i] = translator[ids];
        }
        now_row.swap(new_row);
    }
};

int main() {
    std::string tipe;
    std::cout << "���� ����� ������� ������ �� ����� �������:YES/���� ����� �������� ��������� ������ �������:NO" << std::endl;
    std::cin >> tipe;
    if (tipe == "YES")
    {
        DoKakVMatritse a;
        a.DoKrasivo();
    }
    else if (tipe == "NO")
    {
        int n, am;
        std::cout << "������� ����� ������" << std::endl;
        std::cin >> n;
        std::cout << "������� ���������� �����" << std::endl;
        std::cin >> am;
        DoKakVMatritse a(n, am);
        a.DoKrasivo();
    }
    else
        throw std::invalid_argument("�������� �� ����");
}
