import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import openpyxl
from openpyxl import Workbook
from openpyxl.utils.dataframe import dataframe_to_rows
from openpyxl.chart import LineChart, Reference

# 讀取 CSV 檔案
df = pd.read_csv("result.csv")
df["AvgTime(ns)"] = pd.to_numeric(df["AvgTime(ns)"], errors="coerce")

# 建立 Excel
wb = Workbook()
ws = wb.active
ws.title = "執行時間分析"

# 寫入資料
for row in dataframe_to_rows(df, index=False, header=True):
    ws.append(row)

# 建立圖表（以 Random 資料為例）
filtered = df[df["OrderType"] == "Random"]
algos = filtered["Algorithm"].unique()
sizes = sorted(filtered["DatasetSize"].unique())

chart = LineChart()
chart.title = "Random Data - Sorting Performance"
chart.y_axis.title = "Time (ns)"
chart.x_axis.title = "Dataset Size"

for algo in algos:
    sub = filtered[filtered["Algorithm"] == algo].sort_values("DatasetSize")
    if sub["AvgTime(ns)"].isnull().all():
        continue
    col = 4
    start_row = df[(df["OrderType"] == "Random") & (df["Algorithm"] == algo)].index.min() + 2
    end_row = start_row + len(sub) - 1
    values = Reference(ws, min_col=col, min_row=start_row, max_row=end_row)
    chart.series.append(values)
    chart.series[-1].title = algo

ws.add_chart(chart, "G2")
wb.save("執行時間分析結果.xlsx")
