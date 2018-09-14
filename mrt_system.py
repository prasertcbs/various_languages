def indexStation(stationlist, station):
    for i, a in enumerate(stationlist):
        # print("i = {}, a = {}".format(i, a))
        if a == station:
            return i
    return -1


def stations():
    return ["HUA", "SAM", "SIL", "LUM", "KLO", "QCC",
            "SUK", "PET", "RAM", "CUL", "HUY", "SUT",
            "RAT", "LAD", "PHA", "CHA", "KAM", "BAN"]


def fare(passengerType, noStations):
    adult   = [16, 16, 19, 21, 23, 25, 28, 30, 32, 35, 37, 39, 42, 42, 42, 42, 42, 42]
    child   = [ 8,  8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 21, 21, 21, 21]
    student = [14, 14, 17, 19, 21, 22, 25, 27, 29, 31, 33, 35, 38, 38, 38, 38, 38, 38]
    if passengerType == "A":
        return adult[noStations]
    elif passengerType == "C":
        return child[noStations]
    else:
        return student[noStations]

def fare2(passengerType, noStations):
    # key-value pair
    d = {
        "A":[16, 16, 19, 21, 23, 25, 28, 30, 32, 35, 37, 39, 42, 42, 42, 42, 42, 42],
        "C":[ 8,  8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 21, 21, 21, 21],
        "S":[14, 14, 17, 19, 21, 22, 25, 27, 29, 31, 33, 35, 38, 38, 38, 38, 38, 38],
        "T":[14, 14, 17, 19, 21, 22, 25, 27, 29, 31, 33, 35, 38, 38, 38, 38, 38, 38]
    }
    # print(t["A"][5])
    return d[passengerType][noStations]
    # if passengerType == "A":
    #     return adult[noStations]
    # elif passengerType == "C":
    #     return child[noStations]
    # else:
    #     return student[noStations]

if __name__ == '__main__':
    # fromS = "SAM"
    # toS = "SUK"
    # pType = "A"  # [S]tudent, [C]hild/Senior
    fromS, toS, pType = input("from to ptype: ").upper().split(' ')
    # 5 stations
    # SUK->SIL->KLO->LUM->SIL->SAM
    # 25
    fromIdx = indexStation(stations(), fromS)
    toIdx = indexStation(stations(), toS)
    totalStations = abs(fromIdx - toIdx)
    s = stations()
    if fromIdx < toIdx:
        t = s[fromIdx:toIdx + 1]
    else:
        t = s[fromIdx:toIdx - 1:-1]
    print("->".join(t))
    # print(s[fromIdx:toIdx+1]) # s[1:7]
    # t = s[fromIdx:toIdx+1]
    # print(" -> ".join(t))
    # print(s[6:0:-1])
    print("fare = {}".format(fare("A", totalStations)))
