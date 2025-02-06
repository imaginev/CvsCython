use std::f32::consts::PI;
use std::time::Instant;

fn normal_distribution(x: f32, nx: f32, o: f32) -> f32 {
    let denominator = o * (2.0 * PI).sqrt();
    let z = (x - nx) / o;
    (1.0 / denominator) * (-0.5 * z.powf(2.0)).exp()
}

fn f(b: f32, n: i32) -> f32 {
    let a = 0.0;
    let dx = (b - a) / n as f32;
    let mut sum = 0.0;

    for i in 0..n {
        let xi = a + i as f32 * dx;
        sum += normal_distribution(xi, 0.0, 1.0) * dx;
    }
    sum
}

fn calculate(ei: f32, es: f32, nx: f32, o: f32, n: i32) {
    let t2 = (es - nx) / o;
    let t1 = (ei - nx) / o;
    let _p_suitable_parts = (f(t2, n) - f(t1, n)) * 100.0;

    let t2 = (ei - nx) / o;
    let t1 = -3.0;
    let _p_incorrigible_marriage = (f(t2, n) - f(t1, n)) * 100.0;

    let t2 = 3.0;
    let t1 = (es - nx) / o;
    let _p_fixable_marriage = (f(t2, n) - f(t1, n)) * 100.0;
}

fn test_normal_dist(cycles: i32) -> f64 {
    let start = Instant::now();

    for i in 0..cycles {
        let increment = i as f32 / 10000.0;
        calculate(
            0.006 + increment,
            0.055 + increment,
            0.026 + increment,
            0.012 + increment,
            10000,
        );
    }

    let duration = start.elapsed();
    let secs = duration.as_secs_f64();
    println!("Time: {:.9} seconds", secs);
    secs
}

fn main() {
    let cycles = 1000;
    let count_tests = 10;
    let mut sum = 0.0;

    for _ in 0..count_tests {
        sum += test_normal_dist(cycles);
    }

    println!("Average time: {:.9} seconds", sum / count_tests as f64);
}
