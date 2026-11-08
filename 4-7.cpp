int findLowerLine(const std::vector<Line>& lines, double x, double y) {
    if (lines.empty()) return -1;

    int low = 0;
    int high = lines.size() - 1;

    if (y < lines.front().eval(x)) return -1;
    if (y >= lines.back().eval(x)) return lines.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        double y_mid = lines[mid].eval(x);

        if (y_mid == y) {
            return mid;
        }
        else if (y_mid < y) {
            if (mid + 1 < lines.size() && y < lines[mid + 1].eval(x)) {
                return mid;
            }
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
