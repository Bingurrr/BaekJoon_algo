def solution(genres, plays):
    answer = []
    set_genres = set(genres)
    list_genres = list(set_genres)
    sum_of_play = [ 0 for i in range(len(set_genres))]
    # print(set_generes)
    sum_plays = [[] for i in range(len(set_genres))]
    idx = 0
    for i, j in zip(genres, plays) :
        for k in range(0, len(list_genres)) :
            if list_genres[k] == i :
                sum_plays[k].append((j,idx))
                sum_of_play[k]+=j
        idx+=1      
            
    sum_of_play.sort(key = lambda x : x, reverse = True)
    print(sum_of_play)
    cnt = 0
    ccc = 0
    while(True) :
        # if(ccc == len(set(genres))) :  break
        ccc += 1
        for p in sum_plays :
            print(p)
            k = 0
            p.sort(key = lambda x : x[0], reverse = True)
            for i in range(len(p)) :
                k += p[i][0]
            if k == sum_of_play[0] :
                del sum_of_play[0]
                cnt += 1
                if len(p) >=2 :
                    answer.append(p[0][1])
                    answer.append(p[1][1])
                elif len(p) == 1 :
                    answer.append(p[0][1])
                break
        if(ccc == len(set(genres))) :  break


    return answer