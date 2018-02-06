/**
 * Return the maximum item in array a.
 * Assumes a.size() > 0.
 * Comparable objects must provide operator < and operator =
*/

// ===========================================================

template <typename Comparable>
const Comparable& findMax (const std::vector<Comparable>& a) {
    int max_index = 0;
    auto sz = a.size();
    for (int i = 1; i < sz; ++i) {
        if (a[max_index] < a[i]) max_index = i;
    }
    return max_index;
}