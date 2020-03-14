# coding = utf8

from pyecharts import options as opts
from pyecharts.charts import Line
from pyecharts.render import make_snapshot
from snapshot_selenium import snapshot as driver
import re


def get_html():
    f = open("time.txt", "r")
    lines = f.readlines()

    strs = ""
    for line in lines:
        strs += line
    str_sort = re.findall("(?<=average:) \d+\.?\d*", strs)
    float_sort = [float(i) for i in str_sort]
    chunk_list = list(chunks(float_sort, 6))

    # n = [100, 200, 500, 1000, 2000, 3000], 不能是数字,不然显示不出来,pyecharts 1.7.1
    n = ["100", "200", "500", "1000", "2000", "3000"]
    l = Line(init_opts=opts.InitOpts(width="1200px", height="800px")).add_xaxis(
        xaxis_data=n
    )

    for i in range(6):
        l.add_yaxis(
            series_name=lines[0 + 7 * i].replace("\n", ""),
            y_axis=chunk_list[i],
            is_smooth=True,
            linestyle_opts=opts.LineStyleOpts(width=2),
            # label_opts=opts.LabelOpts(is_show=False),
        )

    l.set_global_opts(
        tooltip_opts=opts.TooltipOpts(is_show=False),
        title_opts=opts.TitleOpts(title="sort"),
        xaxis_opts=opts.AxisOpts(name="n"),
        yaxis_opts=opts.AxisOpts(
            type_="value",
            name="time",
            axislabel_opts=opts.LabelOpts(formatter="{value} s"),
            axistick_opts=opts.AxisTickOpts(is_show=True),
            splitline_opts=opts.SplitLineOpts(is_show=True),
        ),
    )
    l.render("photo.html")


def chunks(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i : i + n]


if __name__ == "__main__":
    get_html()
