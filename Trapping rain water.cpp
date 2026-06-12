#include <iostream>
#include <vector>
using namespace std;
int trapWater(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        }
        else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }
    return water;
}
int main() {
    int n;
    cout << "enter number of bars: ";
    cin >> n;
    vector<int> height(n);
    cout << "enter heights: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout  << trapWater(height) << endl;
    return 0;
}
