# CLion for STM32

## 前言

### 缘起

笔者在学习和实际开发 STM32 的时候，一直使用 Keil 作为 IDE。但是，众所周知，Keil 以其上世纪的 UI、极其卡顿的智能补全以及不能跨平台等缺点，一直饱受诟病。不过不得不承认，Keil 本身的功能十分强大，尤其是其调试能力十分出色。

自从学习 FreeRTOS 之后，笔者发现 Keil 似乎不能很好地调试 FreeRTOS 等一众 RTOS。

> 可能是笔者不会用 Keil 调试 FreeRTOS，如果有大佬知道如何调试，希望大佬不吝赐教！

后来偶然间读到大佬[**稚晖君**](https://space.bilibili.com/20259914?spm_id_from=333.337.0.0)的：[配置CLion用于STM32开发【优雅の嵌入式开发】](https://zhuanlan.zhihu.com/p/145801160)，再加之一直听说 Jetbrains 家的 IDE 功能强大、UI 美观，遂萌生了更换开发环境的想法。

但是当笔者实际操作时发现，稚晖君大佬的这套方案是他于 2022 年写的，而如今已经 2025 年了，稚晖君使用的 MinGW 也早就停止维护了，虽然有可替代的 MinGW-w64，但考虑到**跨平台**、**易用性**以及**易迁移性**，笔者最终选择了 STM32CubeCLT 系列工具重新配置 CLion 的开发环境。

> [!note]
>
> 关于 MinGW 和 MinGW-w64 的区别可以查看这篇文章：[【科普】【FAQ】MinGW vs MinGW-W64 及其它](https://github.com/FrankHB/pl-docs/blob/master/zh-CN/mingw-vs-mingw-v64.md)

> 如果有谁知道这篇文章的原文出处，欢迎告知！

以上便是这篇教程的由来。

### 笔者环境

| 条目         | 版本                                         |
| ------------ | -------------------------------------------- |
| 操作系统     | Windows 11 专业版 24H2 26100.3915            |
| CLion        | CLion 2025.1 CL-251.23774.442 April 15, 2025 |
| STM32CubeCLT | Win 1.18.0                                   |
| STM32CubeMX  | MX.6.14.1                                    |

## 简介

本教程为将 CLion 配置成开发 STM32 IDE 详细步骤，通过本教程，你可以学习到如下知识：

+ 配置 OpenOCD 烧录下载代码
+ 配置 ST-LINK 调试代码
+ 将 MINI ST-LINK V2 转为 ST-LINK
+ 配置 J-LINK 调试代码

## 需求分析

开发 STM32 项目的一般流程如下图所示：

```mermaid
flowchart LR
    A[STM32CubeMX 配置] -->|配置引脚/时钟/外设<br>生成初始化代码| B[IDE 编码]
    B -->|调用 HAL 库<br>实现业务逻辑| C[烧录下载]
    C -->|ST-Link/J-Link<br>SWD/JTAG 接口| D{功能验证}
    D -- 成功 --> E[交付/量产]
    D -- 失败 --> F[调试纠错]
    F -->|逻辑分析仪/断点<br>日志分析/寄存器检查| B

```

可以将这个流程总体归纳为四个步骤：

1. STM32CubeMX 配置
2. IDE 编码
3. 烧录下载
4. 调试纠错

每一个步骤都有相应的软件支持，但我们真正需要的正是一个将这些所有功能集成到一起的 IDE，这样才能简化我们的开发流程。由于 CLion 已经集成了 STM32CubeMX，同时 CLion 本身就是编写代码的 IDE，所以本教程着重从**烧录下载**和**调试纠错**两个方面对 CLion 配置进行讲解。

## 软件下载安装

这里仅给出所需软件的官方下载链接：

+ CLion：[https://www.jetbrains.com/clion/download/#section=windows](https://www.jetbrains.com/clion/download/#section=windows)
+ STM32CubeMX：[https://www.st.com/en/development-tools/stm32cubemx.html](https://www.st.com/en/development-tools/stm32cubemx.html)
+ STM32CubeCLT：[https://www.st.com/en/development-tools/stm32cubeclt.html](https://www.st.com/en/development-tools/stm32cubeclt.html)
+ OpenOCD：[https://gnutoolchains.com/arm-eabi/openocd/](https://gnutoolchains.com/arm-eabi/openocd/)

请读者自行下载安装。

> [!warning]
>
> 所有软件的安装路径不要出现中文。除 CLion 外，其余软件安装路径不能出现中文、空格以及特殊符号。
>
> 因为 CLion 是通过命令行的方式调用其他工具，所以如果路径中出现了中文、空格以及特殊符号，就会导致命令出错。

在这里列出笔者所装软件的路径，以供读者参考：

+ CLion：`D:\Program Files\JetBrains\CLion 2024.3.4`
+ STM32CubeMX：`D:\AppData\Local\Programs\STM32CubeMX`
+ STM32CubeCLT：`D:\ProgramData\ST\STM32CubeCLT`
+ OpenOCD：`D:\ProgramData\OpenOCD`

> [!note]
>
> 注意：笔者这里 CLion 的安装路径虽然是 `CLion 2024.3.4`，这并不意味着笔者使用的是 2024.3.4 版本的 CLion，这只是因为笔者第一次安装 CLion 的时候 CLion 的版本是 2024.3.4。笔者在使用软件的过程中，对软件进行了更新，现在是最新版的。

