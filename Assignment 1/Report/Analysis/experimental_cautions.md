# Experimental cautions


1. Measurements in this package are from the build environment and are not universal.

2. CPU time from `clock()` is process CPU time, not wall-clock latency.

3. A batch of 100 identical searches reduces timer noise but does not model concurrent server load.

4. The three algorithms are measured using identical key sets and targets.

5. Sorting and hash construction are reported separately to avoid hiding preprocessing.

6. For a production SLA, use wall-clock benchmarking, concurrent load testing, and the target deployment hardware.
"
)
