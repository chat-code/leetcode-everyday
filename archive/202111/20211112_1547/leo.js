/**
 * @param {number} n
 * @param {number[]} cuts
 * @return {number}
 */
 var minCost = function (n, cuts) {
    cuts.push(0, n);
    cuts.sort((a, b) => a - b);

    let newDp = [...Array(cuts.length)].map(Element => [...Array(cuts.length)]);

    const dfs = (i, j) => {
        if (j == i + 1) return 0;
        if (newDp[i][j] != undefined) return newDp[i][j];

        for (let k = i + 1; k < j; k++) {
            newDp[i][j] = Math.min(newDp[i][j] || Infinity, dfs(i, k) + dfs(k, j) + cuts[j] - cuts[i]);
        }
        return newDp[i][j];
    }

    return dfs(0, cuts.length - 1);
};