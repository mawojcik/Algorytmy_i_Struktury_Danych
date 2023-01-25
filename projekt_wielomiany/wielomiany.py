class Wielomian:
    def __init__(self, wspolczynniki):
        ilosc_wspolczynnikow = len(wspolczynniki)
        self.wspolczynniki = [None] * ilosc_wspolczynnikow

        for i in range(ilosc_wspolczynnikow):
            self.wspolczynniki[i] = float(wspolczynniki[i])

    def __add__(self, other):
        ilosc_wsp_1 = len(self.wspolczynniki)
        ilosc_wsp_2 = len(other.wspolczynniki)

        if ilosc_wsp_1 > ilosc_wsp_2:
            wspolczynniki = [None] * ilosc_wsp_1
            for i in range(ilosc_wsp_2):
                wspolczynniki[i] = self.wspolczynniki[i] + other.wspolczynniki[i]

            for i in range(ilosc_wsp_2, ilosc_wsp_1):
                wspolczynniki[i] = self.wspolczynniki[i]

        else:
            wspolczynniki = [None] * ilosc_wsp_2
            for i in range(ilosc_wsp_1):
                wspolczynniki[i] = self.wspolczynniki[i] + other.wspolczynniki[i]

            for i in range(ilosc_wsp_1, ilosc_wsp_2):
                wspolczynniki[i] = other.wspolczynniki[i]

        return Wielomian(wspolczynniki)

    def __sub__(self, drugi):
        ilosc_wsp_1 = len(self.wspolczynniki)
        ilosc_wsp_2 = len(drugi.wspolczynniki)

        if ilosc_wsp_1 > ilosc_wsp_2:
            wspolczynniki = [None] * ilosc_wsp_1
            for i in range(ilosc_wsp_2):
                wspolczynniki[i] = self.wspolczynniki[i] - drugi.wspolczynniki[i]

            for i in range(ilosc_wsp_2, ilosc_wsp_1):
                wspolczynniki[i] = self.wspolczynniki[i]
        else:
            wspolczynniki = [None] * ilosc_wsp_2
            for i in range(ilosc_wsp_1):
                wspolczynniki[i] = self.wspolczynniki[i] - drugi.wspolczynniki[i]

            for i in range(ilosc_wsp_1, ilosc_wsp_2):
                wspolczynniki[i] = -drugi.wspolczynniki[i]

        return Wielomian(wspolczynniki)

    def __mul__(self, other):
        ilosc_wsp_1 = len(self.wspolczynniki)
        ilosc_wsp_2 = len(other.wspolczynniki)
        wspolczynniki = [None] * (ilosc_wsp_1 + ilosc_wsp_2 - 1)

        for i in range(ilosc_wsp_1):
            for j in range(ilosc_wsp_2):
                if wspolczynniki[i + j] is None:
                    wspolczynniki[i + j] = self.wspolczynniki[i] * other.wspolczynniki[j]
                else:
                    wspolczynniki[i + j] += self.wspolczynniki[i] * other.wspolczynniki[j]

        return Wielomian(wspolczynniki)

    def __str__(self):
        wielomian = ""
        ilosc_wsp = len(self.wspolczynniki)

        for i in range(ilosc_wsp):
            wartosc = self.wspolczynniki[i]
            if wartosc:
                znak = None
                if wartosc < 0:
                    znak = '-'
                else:
                    znak = '+'

                czynnik = None

                if i == 0:
                    czynnik = str(abs(wartosc))
                elif i == 1:
                    if abs(wartosc) == 1.0:
                        czynnik = 'x'
                    else:
                        czynnik = str(abs(wartosc)) + 'x'
                else:
                    if abs(wartosc) == 1.0:
                        czynnik = 'x^' + str(i)
                    else:
                        czynnik = str(abs(wartosc)) + 'x^' + str(i)

                czynnik = czynnik.replace('.0', '')
                wielomian += ' ' + znak + ' ' + czynnik

        znak = wielomian[1]
        wielomian = wielomian.removeprefix(' ' + znak + ' ')

        if znak == '-':
            wielomian = znak + wielomian

        return wielomian

    def horner(self, x):
        wynik = 0
        for i in range(len(self.wspolczynniki) - 1, -1, -1):
            wynik = wynik * x + self.wspolczynniki[i]

        return wynik


w1 = Wielomian([0, -1, 7, -1])
w2 = Wielomian([2, 4.4, 1, 2])
w3 = w1*w2

print("W1(-3) = ", w1.horner(-3))
print("W3(-5.2) = ", w3.horner(5.2))
print("W(x) = ", w2)
