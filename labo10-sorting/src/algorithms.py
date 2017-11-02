from list_algorithms import presentar
import random

grupo = 'ezequiel'


# ATENCION: 
# - descomentar el "@presentar" y dejarlo solamente en las implementaciones de los algoritmos a entregar
# - pueden agregar las funciones auxiliares que necesiten en este mismo archivo
# - solo se permite un unico envio


# @presentar
def insertion_sort(a):
    return a


def reverse(a):
    for i in len(a)/2:
        swap(a, i, len(a)-i)

@presentar
def selection_sort(a):
    ordered = True
    reverseOrdered = True
    for i in range(len(a) - 1):
        ai, ai1 = a[i], a[i + 1]
        if ai > ai1:
            ordered = False
        if ai < ai1:
            reverseOrdered = False
        if not ordered and not reverseOrdered:
            break
    if ordered:
        return a
    if reverseOrdered:
        reverse(a)
        return a
    for j in range(len(a)):
        min = a[j]
        min_ix = j
        for i in range(j, len(a)):
            new_min = a[i]
            if new_min < min:
                min = new_min
                min_ix = i
        tmp = a[j]
        a[j] = a[min_ix]
        a[min_ix] = tmp
    return a


# @presentar
def quicksort(a):
    return a


@presentar
def heapsort(a):
    largo = len(a)
    mitad = padre(largo) + 1
    for i in range(mitad, -1, -1):
        sift_down(a, i, largo)
    res_size = 1
    while res_size <= largo:
        tmp = a[largo - res_size]
        a[largo - res_size] = a[0]
        a[0] = tmp
        sift_down(a, 0, largo - res_size)
        res_size += 1
    return a


def swap(a, b, c):
    a[b], a[c] = a[c], a[b]


def sift_down(a, i, end):
    root = i
    while hijoIzquierdo(root) < end:
        hijoIzq = hijoIzquierdo(root)
        hijoIzqVal = a[hijoIzq]
        swapi = root
        rootVal = a[root]
        if rootVal < hijoIzqVal:
            swapi = hijoIzq
        if swapi == root:
            aSwapi = rootVal
        else:
            aSwapi = a[swapi]
        if hijoDerecho(root) < end and aSwapi < a[hijoDerecho(root)]:
            swapi = hijoDerecho(root)
        if swapi == root:
            break
        else:
            a[root] = a[swapi]
            a[swapi] = rootVal
            root = swapi


def padre(n):
    return int(n / 2)


def hijoIzquierdo(n):
    return 2 * n + 1


def hijoDerecho(n):
    return 2 * n + 2


# @presentar
def mergesort(a):
    b = a.crear_temporal()
    mergeSort(a, b, 0, len(a))
    return a


def mergeSort(a, b, start, end):
    ordered = True
    reverseOrdered = True
    for i in range(len(a) - 1):
        ai, ai1 = a[i], a[i + 1]
        if ai > ai1:
            ordered = False
        if ai < ai1:
            reverseOrdered = False
        if not ordered and not reverseOrdered:
            break
    if ordered:
        return a
    if reverseOrdered:
        reverse(a)
        return a
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            ordered = False
    if ordered:
        return a
    if (end - start <= 2):
        izq = a[0]
        der = a[1]
        if izq > der:
            a[0] = der
            a[1] = izq
        return

    mitad = int(len(a) / 2)
    mergeSort(a, start, mitad)
    mergeSort(a, mitad, end)
