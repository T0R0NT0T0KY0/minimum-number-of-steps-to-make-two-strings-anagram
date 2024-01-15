function minSteps(s: string, t: string): number {
	const sCharCountMap = new Map<string, number>();
	const tCharCountMap = new Map<string, number>();

	for (let i = 0; i < s.length; ++i) {
		const sChar = s[i];
		sCharCountMap.set(sChar, (sCharCountMap.get(sChar) ?? 0) + 1);

		const tChar = t[i];
		tCharCountMap.set(tChar, (tCharCountMap.get(tChar) ?? 0) + 1);
	}

	let steps = 0;

	for (const [sChar, sCharCount] of sCharCountMap) {
		const tCharCount = tCharCountMap.get(sChar) ?? 0;
		steps += Math.max(sCharCount - tCharCount, 0);
	}

	return steps;
}

const res1 = minSteps("bab", "aba");
console.log(`test1: ${res1}`);

const res2 = minSteps("leetcode", "practice");
console.log(`test2: ${res2}`);

const res3 = minSteps("anagram", "mangaar");
console.log(`test3: ${res3}`);
