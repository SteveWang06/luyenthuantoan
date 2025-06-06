#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iomanip>


using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// Quick Sort
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    quickSortHelper(arr, low, i);
    quickSortHelper(arr, i + 2, high);
}
void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Shell Sort（自選）
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i], j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// ----------- 工具方法 ------------

// 從 CSV 中解析一行為 vector<int>
vector<int> parseCSVLine(const string& line) {
    vector<int> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, ','))
        result.push_back(stoi(item));
    return result;
}

// 計算某排序法重複多次後的平均時間（奈秒）
template<typename SortFunc>
long long averageExecutionTime(SortFunc sortFunc, const vector<int>& original, int repeat = 5) {
    vector<long long> times;
    for (int i = 0; i < repeat; ++i) {
        vector<int> temp = original;
        auto start = high_resolution_clock::now();
        sortFunc(temp);
        auto end = high_resolution_clock::now();
        times.push_back(duration_cast<nanoseconds>(end - start).count());
    }
    return accumulate(times.begin(), times.end(), 0LL) / repeat;
}

int sortmain() {
    ifstream file("data.csv");
    ofstream output("result.csv");
    output << "DatasetSize,OrderType,Algorithm,AvgTime(ns)\n";

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        cout << "Processing " << lineNumber + 1 << " Group..." << endl;

        vector<int> data = parseCSVLine(line);
        int size = data.size();
        string orderType;

        if (lineNumber < 10) orderType = "Random";
        else if (lineNumber < 20) orderType = "Ascending";
        else orderType = "Descending";

        output << fixed << setprecision(0);

        // 如果資料量不大（避免卡死）
        if (size <= 3200) {
            output << size << "," << orderType << ",BubbleSort," << averageExecutionTime(bubbleSort, data) << "\n";
            output << size << "," << orderType << ",InsertionSort," << averageExecutionTime(insertionSort, data) << "\n";
            output << size << "," << orderType << ",SelectionSort," << averageExecutionTime(selectionSort, data) << "\n";
        } else {
            output << size << "," << orderType << ",BubbleSort,SKIPPED\n";
            output << size << "," << orderType << ",InsertionSort,SKIPPED\n";
            output << size << "," << orderType << ",SelectionSort,SKIPPED\n";
        }

        // 快速排序、std::sort 與 shell sort 執行
        output << size << "," << orderType << ",QuickSort," << averageExecutionTime(quickSort, data) << "\n";
        output << size << "," << orderType << ",StdSort," << averageExecutionTime([](vector<int>& v) {
            sort(v.begin(), v.end());
        }, data) << "\n";
        output << size << "," << orderType << ",ShellSort," << averageExecutionTime(shellSort, data) << "\n";

        ++lineNumber;
    }

    output.close();
    file.close();
    cout << "Sorting is complete and the results have been output to result.csv!" << endl;
    return 0;
}

int main() {
    auto start = high_resolution_clock::now(); // 計時開始
    sortmain(); // 這裡放入你要計時的程式碼
    auto end = high_resolution_clock::now(); // 計時結束
    auto durationStd = duration_cast<nanoseconds>(end - start); // 計算耗時
    cout << "std::sort 花費時間: " << durationStd.count() << " 10^-9秒" << endl;
    return 0;
}