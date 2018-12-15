头文件保护符（header guard）使用预处理变量以防止头文件被某个文件重复包含。

见p68。

my note: 还可以使用另一种方法，即在文件开头使用`#pragma once`令编译器保证同一个文件不被包含多次。其功能和header guard只有一点细微的区别：

- 可以避免因header guard重复所导致的奇怪编译错误

- 不是所有编译器都支持

参考资料：http://www.cnblogs.com/Braveliu/archive/2012/12/29/2838726.html
