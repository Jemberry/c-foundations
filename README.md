# C-foundations

> This project is my personal practice repository for learning C language basics and data structures.
> 记录 C 语言基础语法与数据结构的学习历程，构建底层编程逻辑。

---

## 📌 项目简介
本项目是我学习 C 语言及经典数据结构的实战仓库。通过手动实现每一个基础算法和结构，旨在深入理解：
* **内存管理**：堆栈分配、指针操作与内存泄漏预防。
* **算法逻辑**：时间与空间复杂度的权衡。
* **底层原理**：C 语言如何直接与硬件及内存交互。

---

## 📂 目录结构说明

| 文件夹 | 描述 | 关键点 |
| :--- | :--- | :--- |
| `01_Basics/` | C 语言基础语法 | 数据类型、控制流、函数 |
| `02_Pointers/` | 指针专项练习 | 一级/多级指针、函数指针、数组指针 |
| `03_Memory/` | 动态内存管理 | `malloc`, `free`, `realloc` 的使用 |
| `04_Linear_List/` | 线性表 | 顺序表、单链表、双向链表、循环链表 |
| `05_Stack_Queue/` | 栈与队列 | 顺序栈、链式队列、循环队列 |
| `06_Trees/` | 树结构 | 二叉树遍历、BST 搜索树、AVL 平衡树 |
| `07_Sorting/` | 经典排序算法 | 快排、归并、堆排序、冒泡 |

---

## 🛠️ 环境配置
* **编译器**: `gcc` (Recommended) 或 `clang`
* **构建工具**: `make` (可选)
* **操作系统**: Windows (MinGW/WSL) / macOS / Linux

### 快速编译示例
进入对应的文件夹，执行以下命令：
```bash
# 编译
gcc main.c -o output_name

# 运行
./output_name
