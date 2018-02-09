void ema(const double CLOSE[], double ema[], const int N, const int PERIOD,
		const int TIMEFRAME);

void ema(const double CLOSE[], double ema[], const int N, const int PERIOD,
		const int TIMEFRAME)
{
	static int    last_timeframe  = 0;
	const  double ALPHA           = 2.0 / (PERIOD + 1.0);
	static int    last_calculated = 0;

	if (last_timeframe != TIMEFRAME) {
		last_calculated = 0;

		last_timeframe = TIMEFRAME;
	}

	for (int i = last_calculated; i < N; i++) {
		if (i == 0) {
			ema[i] = CLOSE[i];
		} else {
			ema[i] = ALPHA * CLOSE[i] + (1.0 - ALPHA) * ema[i - 1];
		}

		last_calculated = i;
	}
}
