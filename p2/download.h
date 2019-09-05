#define ELAPSED_TIME(t, st) (t - st)
#define PERCENT_COMPLETE(b, tb) ((b/tb)*100)
#define DOWNLOAD_SPEED(t, st, b) ((b)/(t - st))
#define TOTAL_TIME(t, st, b, tb) (tb/((b)/(t-st)))
#define REMAINING_TIME(t, st, b, tb) ((tb/((b)/(t-st))) - (t-st))

