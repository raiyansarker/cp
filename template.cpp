#include <bits/stdc++.h>
using namespace std;

// =================== YOUR DEBUG TEMPLATE BEGINS HERE ===================

#ifndef NDEBUG

#include <chrono>

// --- Helper functions to pretty-print common data structures ---
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type>
std::ostream& operator<<(std::ostream& os, const T_container& v) {
  os << "{";
  std::string sep;
  for (const T& x : v) {
      os << sep << x;
      sep = ", ";
  }
  return os << "}";
}

// --- The core debug macro ---
#define debug(...) std::cerr << "[Line " << __LINE__ << "]: " << #__VA_ARGS__ << " = ", _print(__VA_ARGS__)

// --- Variadic template function to print all arguments ---
void _print() {
    std::cerr << std::endl;
}

template<typename T, typename... V>
void _print(T t, V... v) {
  std::cerr << t;
  if (sizeof...(v)) {
      std::cerr << ", ";
  }
  _print(v...);
}

// --- Optional: A timer utility ---
class Timer {
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
public:
  Timer() {
    start_time = std::chrono::high_resolution_clock::now();
  }
  ~Timer() {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cerr << "[Timer]: " << duration.count() << " ms" << std::endl;
  }
};

#define time_block Timer timer_in_scope_

#else
#define debug(...)
#define time_block

#endif

// =================== YOUR DEBUG TEMPLATE ENDS HERE ===================

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);



  return 0;
}
