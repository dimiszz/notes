def media(a):
    mean = 0
    count = 0
    for i in a:
        if i == "":
            continue
        count += 1
        mean += float(i)
    mean /= count
    print(mean)




lake_house = "8.7|8.5|8.3|5|9.7|7|9|8".split("|")
paraiso = "9.0|8.5|8.5|8.5|9.2|6|8.5|8".split("|")
pedra = "8.8|8|7.5|10|8.7|6|6|6".split("|")
banheira = "8.9|8.9|9.3|9|9|8|9|9".split("|")
pier = "8.3|7|7.8".split("|")

media(lake_house)
media(paraiso)
media(pedra)
media(banheira)
media(pier)