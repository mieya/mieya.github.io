---
title: Dlinear短时间序列预测效果
date: 2023-03-07 10:38:42
categories: 组会
tags:
- Dlinear
- TSF
---

### 预测一天

![预测一天.png](https://s1.ax1x.com/2023/03/07/ppZrs0g.png)

<!--more-->

![预测一天2.png](https://s1.ax1x.com/2023/03/07/ppZrbN9.png)



### 预测三天

![预测三天.png](https://s1.ax1x.com/2023/03/07/ppZrznO.png)



![预测三天2.png](https://s1.ax1x.com/2023/03/07/ppZspHe.png)



### 预测五天

![预测五天.png](https://s1.ax1x.com/2023/03/07/ppZsi4A.png)



![预测五天2.png](https://s1.ax1x.com/2023/03/07/ppZsnHg.png)



### 下周安排

截至2023年2月，五种不同任务各自的TOP3模型是：(排行榜来自https://github.com/thuml/Time-Series-Library)

| Model Ranking | Long-term Forecasting                                        | Short-term Forecasting                                       | Imputation                                                   | Anomaly Detection                                            | Classification                                     |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------------------------------------------------- |
| 🥇 1st         | [TimesNet](https://arxiv.org/abs/2210.02186)                 | [TimesNet](https://arxiv.org/abs/2210.02186)                 | [TimesNet](https://arxiv.org/abs/2210.02186)                 | [TimesNet](https://arxiv.org/abs/2210.02186)                 | [TimesNet](https://arxiv.org/abs/2210.02186)       |
| 🥈 2nd         | [DLinear](https://github.com/cure-lab/LTSF-Linear)           | [Non-stationary Transformer](https://github.com/thuml/Nonstationary_Transformers) | [Non-stationary Transformer](https://github.com/thuml/Nonstationary_Transformers) | [Non-stationary Transformer](https://github.com/thuml/Nonstationary_Transformers) | [FEDformer](https://github.com/MAZiqing/FEDformer) |
| 🥉 3rd         | [Non-stationary Transformer](https://github.com/thuml/Nonstationary_Transformers) | [FEDformer](https://github.com/MAZiqing/FEDformer)           | [Autoformer](https://github.com/thuml/Autoformer)            | [Informer](https://github.com/zhouhaoyi/Informer2020)        | [Autoformer](https://github.com/thuml/Autoformer)  |

可以看到短时间序列预测中当前的TOP3为：

[TimesNet](https://arxiv.org/abs/2210.02186)、[Non-stationary Transformer](https://github.com/thuml/Nonstationary_Transformers)、[FEDformer](https://github.com/MAZiqing/FEDformer)。

- 复现不同的模型并对比实验效果
- 检索并阅读相关文献


