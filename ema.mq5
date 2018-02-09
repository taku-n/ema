#import "ema.dll"
void ema(const double &CLOSE[], double &ema[], const int N, const int PERIOD,
		const int TIMEFRAME);
#import

input int PERIOD = 10;

#property indicator_chart_window

#property indicator_buffers 1
#property indicator_plots   1

#property indicator_label1 "EMA"
#property indicator_type1  DRAW_LINE
#property indicator_color1 clrRed
#property indicator_style1 STYLE_SOLID
#property indicator_width1 1

double ema[];

int OnInit()
{
	SetIndexBuffer(0, ema, INDICATOR_DATA);

	PlotIndexSetString(0, PLOT_LABEL, "EMA(" + PERIOD + ")");

	return INIT_SUCCEEDED;
}

int OnCalculate(const int       rates_total,
		const int       prev_calculated,
		const datetime &time[],
		const double   &open[],
		const double   &high[],
		const double   &low[],
		const double   &close[],
		const long     &tick_volume[],
		const long     &volume[],
		const int      &spread[])
{
	ema(close, ema, rates_total, PERIOD, Period());

	return rates_total;
}