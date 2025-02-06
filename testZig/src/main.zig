const std = @import("std");
const math = std.math;

fn normalDistribution(x: f32, nx: f32, o: f32) f32 {
    const pi: f32 = @floatCast(math.pi);
    const two_pi: f32 = 2.0 * pi;
    const denominator: f32 = o * math.sqrt(two_pi);
    const z: f32 = (x - nx) / o;
    const exponent: f32 = -0.5 * math.pow(f32, z, 2.0);
    return (1.0 / denominator) * math.exp(exponent);
}

fn F(b: f32, n: i32) f32 {
    const a: f32 = 0.0;
    const dx: f32 = (b - a) / @as(f32, @floatFromInt(n));
    var sum: f32 = 0.0;
    var i: i32 = 0;
    while (i < n) : (i += 1) {
        const xi: f32 = a + @as(f32, @floatFromInt(i)) * dx;
        sum += normalDistribution(xi, 0.0, 1.0) * dx;
    }
    return sum;
}

fn calculate(ei: f32, es: f32, nx: f32, o: f32, n: i32) void {
    var t2: f32 = undefined;
    var t1: f32 = undefined;
    var p_suitable_parts: f32 = undefined;
    var p_incorrigible_marriage: f32 = undefined;
    var p_fixable_marriage: f32 = undefined;

    t2 = (es - nx) / o;
    t1 = (ei - nx) / o;
    p_suitable_parts = (F(t2, n) - F(t1, n)) * 100.0;

    t2 = (ei - nx) / o;
    t1 = -3.0;
    p_incorrigible_marriage = (F(t2, n) - F(t1, n)) * 100.0;

    t2 = 3.0;
    t1 = (es - nx) / o;
    p_fixable_marriage = (F(t2, n) - F(t1, n)) * 100.0;

    // _ = p_suitable_parts;
    // _ = p_incorrigible_marriage;
    // _ = p_fixable_marriage;
}

fn testNormalDist(cycles: i32) f64 {
    const start = std.time.nanoTimestamp();

    var i: i32 = 0;
    while (i < cycles) : (i += 1) {
        const increment: f32 = @as(f32, @floatFromInt(i)) / 10000;
        const ei: f32 = 0.006 + increment;
        const es: f32 = 0.055 + increment;
        const nx: f32 = 0.026 + increment;
        const o: f32 = 0.012 + increment;
        calculate(ei, es, nx, o, 10000);
    }

    const end = std.time.nanoTimestamp();
    const duration_ns: i128 = end - start;
    const duration_sec: f64 = @as(f64, @floatFromInt(duration_ns)) / 1e9;
    std.debug.print("Time: {d:.9} seconds\n", .{duration_sec});
    return duration_sec;
}

pub fn main() !void {
    const cycles: i32 = 1000;
    const countTests: i32 = 10;
    var sum: f64 = 0.0;

    var i: i32 = 0;
    while (i < countTests) : (i += 1) {
        sum += testNormalDist(cycles);
    }

    const avg = sum / @as(f64, @floatFromInt(countTests));
    std.debug.print("Average time: {d:.9} seconds\n", .{avg});
}
