function normal_distribution(x, nx = 0, o = 1) {
    return (1 / (o * Math.sqrt(2 * Math.PI))) * Math.exp(-0.5 * ((x - nx) / o) ** 2);
}

function F(b, n = 10000) {
    const a = 0;
    const dx = (b - a) / n;
    let sum = 0;

    let xi;
    for (let i = 0; i < n; i++) {
        xi = a + i * dx;
        sum += normal_distribution(xi) * dx;
    }

    return sum;
}

function calculate(ei, es, nx, o, n) {
    let t2 = (es - nx) / o;
    let t1 = (ei - nx) / o;
    const p_suitable_parts = (F(t2, n) - F(t1, n)) * 100;

    t2 = (ei - nx) / o;
    t1 = (nx - 3 * o - nx) / o;
    const p_incorrigible_marriage = (F(t2, n) - F(t1, n)) * 100;

    t2 = (nx + 3 * o - nx) / o;
    t1 = (es - nx) / o;
    const p_fixable_marriage = (F(t2, n) - F(t1, n)) * 100;

    return {
        p_suitable_parts,
        p_incorrigible_marriage,
        p_fixable_marriage
    };
}

function test_normal_dist(cycles) {
    const start = performance.now();

    for (let i = 0; i < cycles; i++) {
        calculate(0.006+i/10000, 0.055+i/10000, 0.026+i/10000, 0.012+i/10000, 10000);
    }

    const end = performance.now();
    const totalTime = (end - start) / 1000;
    console.log(`Time: ${totalTime} seconds`);
    return totalTime;
}

const cycles = 1000;
const countTests = 10;
let sum = 0;

for (let i = 0; i < countTests; i++) { 
    sum += test_normal_dist(cycles);
}
console.log(`Current time: ${sum / countTests}\n`);