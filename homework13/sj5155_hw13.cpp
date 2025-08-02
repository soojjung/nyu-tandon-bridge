#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Organism {
    // Organism은 개미(Ant)와 두들버그(Doodlebug)의 공통 동작을 정의한
    // 추상클래스 상속용으로만 사용되며, 직접 객체를 생성하지 않는다.

   protected:  // protected로 선언하면 자식 클래스는 직접 접근 가능하지만,
               // 외부에서는 불가
    int x, y;  // 현재 위치 (x: 행 번호, y: 열 번호)
    int stepsSurvived;  // 얼마나 많은 타임스텝 동안 살아남았는지 카운트. (번식
                        // 조건 위해 필요)
    bool moved;

   public:
    Organism(int x, int y)
        : x(x), y(y), stepsSurvived(0), moved(false) {}  // 초기화
    virtual ~Organism() {}                               // 가상 소멸자
    virtual void move(Organism* grid[20][20]) = 0;
    virtual void breed(
        Organism* grid[20][20]) = 0;     // 번식 동작을 자식 클래스가 구현
    virtual char getSymbol() const = 0;  // 해당 생물을 격자에 표시할 때
                                         // 사용하는 ASCII 문자 반환 (예: o, X)

    void setMoved(bool m) { moved = m; }
    bool hasMoved() const { return moved; }

    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    int getStepsSurvived() const { return stepsSurvived; }
    void incrementSurvival() { stepsSurvived++; }
};

class Ant : public Organism {
   public:
    Ant(int x, int y) : Organism(x, y) {}
    void move(Organism* grid[20][20]) override {
        if (hasMoved())
            return;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        random_shuffle(directions.begin(), directions.end());

        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 &&
                grid[newX][newY] == nullptr) {
                grid[newX][newY] = this;
                grid[x][y] = nullptr;
                setPosition(newX, newY);
                break;
            }
        }

        setMoved(true);
        incrementSurvival();
    }

    void breed(Organism* grid[20][20]) override {
        if (getStepsSurvived() < 3)
            return;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        random_shuffle(directions.begin(), directions.end());

        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 &&
                grid[newX][newY] == nullptr) {
                grid[newX][newY] = new Ant(newX, newY);
                setMoved(true);
                break;
            }
        }

        if (hasMoved())
            stepsSurvived = 0;
    }

    char getSymbol() const override { return 'o'; }
};

class Doodlebug : public Organism {
   private:
    int stepsSinceLastMeal;

   public:
    Doodlebug(int x, int y) : Organism(x, y), stepsSinceLastMeal(0) {}

    void move(Organism* grid[20][20]) override {
        if (hasMoved())
            return;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20) {
                Ant* ant = dynamic_cast<Ant*>(grid[newX][newY]);
                if (ant != nullptr) {
                    delete grid[newX][newY];
                    grid[newX][newY] = this;
                    grid[x][y] = nullptr;
                    setPosition(newX, newY);
                    stepsSinceLastMeal = 0;
                    setMoved(true);
                    incrementSurvival();
                    return;
                }
            }
        }

        random_shuffle(directions.begin(), directions.end());
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 &&
                grid[newX][newY] == nullptr) {
                grid[newX][newY] = this;
                grid[x][y] = nullptr;
                setPosition(newX, newY);
                break;
            }
        }

        stepsSinceLastMeal++;
        setMoved(true);
        incrementSurvival();
    }

    void breed(Organism* grid[20][20]) override {
        if (getStepsSurvived() < 8)
            return;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        random_shuffle(directions.begin(), directions.end());

        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 &&
                grid[newX][newY] == nullptr) {
                grid[newX][newY] = new Doodlebug(newX, newY);
                setMoved(true);
                break;
            }
        }

        if (hasMoved())
            stepsSurvived = 0;
    }

    void starve(Organism* grid[20][20]) {
        if (stepsSinceLastMeal >= 3) {
            delete grid[x][y];
            grid[x][y] = nullptr;
        }
    }

    char getSymbol() const override { return 'X'; }
};

class World {
   private:
    Organism* grid[20][20];

   public:
    World() {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) grid[i][j] = nullptr;
    }

    ~World() {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) delete grid[i][j];
    }

    void initialize() {
        srand(time(0));
        int ants = 0, doodles = 0;

        while (ants < 100) {
            int x = rand() % 20;
            int y = rand() % 20;
            if (grid[x][y] == nullptr) {
                grid[x][y] = new Ant(x, y);
                ants++;
            }
        }

        while (doodles < 5) {
            int x = rand() % 20;
            int y = rand() % 20;
            if (grid[x][y] == nullptr) {
                grid[x][y] = new Doodlebug(x, y);
                doodles++;
            }
        }
    }

    void display() const {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (grid[i][j] == nullptr)
                    cout << "-";
                else
                    cout << grid[i][j]->getSymbol();
            }
            cout << endl;
        }
    }

    void simulateStep() {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j)
                if (grid[i][j] != nullptr)
                    grid[i][j]->setMoved(false);

        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) {
                Doodlebug* d = dynamic_cast<Doodlebug*>(grid[i][j]);
                if (d != nullptr && !d->hasMoved())
                    d->move(grid);
            }

        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) {
                Ant* a = dynamic_cast<Ant*>(grid[i][j]);
                if (a != nullptr && !a->hasMoved())
                    a->move(grid);
            }

        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) {
                Doodlebug* d = dynamic_cast<Doodlebug*>(grid[i][j]);
                if (d != nullptr)
                    d->breed(grid);
            }

        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) {
                Ant* a = dynamic_cast<Ant*>(grid[i][j]);
                if (a != nullptr)
                    a->breed(grid);
            }

        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j) {
                Doodlebug* d = dynamic_cast<Doodlebug*>(grid[i][j]);
                if (d != nullptr)
                    d->starve(grid);
            }
    }
};

int main() {
    World world;
    world.initialize();

    while (true) {
        world.display();
        cout << "\nPress Enter to continue...";
        cin.get();
        world.simulateStep();
    }

    return 0;
}
