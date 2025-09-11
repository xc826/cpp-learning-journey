当你在Linux终端运行C++程序时出现 `sh: 1: pause: not found` 错误，这通常意味着你的代码中使用了 `system("pause")` 语句。

这个问题的原因是：
- `pause` 命令是Windows系统下的命令，用于让控制台暂停并显示"按任意键继续..."
- Linux系统中没有 `pause` 这个命令，所以会提示"未找到"

解决方法很简单，将代码中的：
```cpp
system("pause");
```

替换为Linux下的等效命令：
```cpp
system("read -p '按任意键继续...' var");
```

或者如果你想完全跨平台，可以使用条件编译：
```cpp
#ifdef _WIN32
    system("pause");
#else
    system("read -p '按任意键继续...' var");
#endif
```

这样修改后，程序在Windows系统会使用 `pause` 命令，在Linux系统会使用 `read` 命令来实现暂停功能。



终端运行cpp代码
1. g++ filename.cpp -o filename
2. ./filename

> 但是要注意，使用数组来做哈希的题目，是因为题目都限制了数值的大小。
而这道题目没有限制数值的大小，就无法使用数组来做哈希表了。
而且如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费。
此时就要使用另一种结构体了，set ，关于set，C++ 给提供了如下三种可用的数据结构：
std::set
std::multiset
std::unordered_set
std::set和std::multiset底层实现都是红黑树，std::unordered_set的底层实现是哈希表， 使用unordered_set 读写效率是最高的，并不需要对数据进行排序，而且还不要让数据重复，所以选择unordered_set。



这是因为你在新文件名中使用了括号 `(` 和 `)`，而这两个符号在 Bash 命令行中属于特殊字符（用于分组和子命令），直接使用会导致解析错误。

解决方法有两种：

1. **给文件名加上引号**（推荐）：
   ```bash
   mv 28.cpp "28(KMP).cpp"
   ```
   单引号或双引号都可以，引号会告诉 Bash 把括号当作普通字符处理。

2. **使用转义字符 `\`**：
   ```bash
   mv 28.cpp 28\(KMP\).cpp
   ```
   在每个特殊字符（`(` 和 `)`）前加上 `\`，表示该字符为普通字符。

虽然 Linux 允许文件名包含这些特殊字符，但建议尽量避免在文件名中使用 `( ) [ ] { } ! @ # $ & * ?` 等符号，以免带来类似的命令行操作问题。