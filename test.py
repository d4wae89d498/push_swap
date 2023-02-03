

def note_liste(lst):
    n = len(lst)
    sorted_lst = sorted(lst)
    max_score = 0
    for i in range(n):
        score = 0
        for j in range(n):
            if lst[j] == sorted_lst[(j + i) % n]:
                score += 1
        if score == n - 1 and lst[0] > lst[1]:
            score += 1
        max_score = max(max_score, score)
    return max_score / n


print note_liste([1, 3, 4, 2]) < note_liste([2, 3, 1, 4]);

print note_liste([1, 4, 2, 3]) < note_liste([1, 3, 4, 2]);
print note_liste([1, 4, 2, 3]) < note_liste([2, 3, 1, 4]);
