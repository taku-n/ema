void ema(const double CLOSE[], double ema[], const int START,
		const int END, const int PERIOD);

void ema(const double CLOSE[], double ema[], const int START,
		const int END, const int PERIOD)
{
	const double ALPHA = 2.0 / (PERIOD + 1.0);

	for (int i = START; i <= END; i++) {
		if (i == 0) {
			ema[i] = CLOSE[i];
		} else {
			ema[i] = ALPHA * CLOSE[i]
					+ (1.0 - ALPHA) * ema[i - 1];
		}
	}
}
