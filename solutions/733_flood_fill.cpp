// Time  complexity: O(N*M)
// Space complexity: O(N*M)
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color) {
        const int curr = image.at(sr).at(sc);
        if (curr == color) return image;

        image.at(sr).at(sc) = color;

        if (sr - 1 >= 0 && curr == image.at(sr - 1).at(sc)) {
            floodFill(image, sr - 1, sc, color);
        }
        if (sr + 1 < image.size() && curr == image.at(sr + 1).at(sc)) {
            floodFill(image, sr + 1, sc, color);
        }
        if (sc - 1 >= 0 && curr == image.at(sr).at(sc - 1)) {
            floodFill(image, sr, sc - 1, color);
        }
        if (sc + 1 < image.at(0).size() && curr == image.at(sr).at(sc + 1)) {
            floodFill(image, sr, sc + 1, color);
        }

        return image;
    }
};
