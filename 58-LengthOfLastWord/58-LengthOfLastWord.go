// Last updated: 5/20/2026, 11:37:41 PM
func lengthOfLastWord(s string) int {
	words := strings.Fields(s)
	if len(words) == 0 {
		return 0
	}

	return len(words[len(words)-1])
}