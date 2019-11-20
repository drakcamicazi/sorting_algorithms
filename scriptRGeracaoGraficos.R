Insercao <- read.csv("~/Desktop/UPAR ESSAS COISAS AQUI/trabic2/trabVCompMov/Insercao.txt", sep=";")
Selecao <- read.csv("~/Desktop/UPAR ESSAS COISAS AQUI/trabic2/trabVCompMov/Selecao.txt", sep=";")
HeapSort <- read.csv("~/Desktop/UPAR ESSAS COISAS AQUI/trabic2/trabVCompMov/HeapSort.txt", sep=";")
QuickSort <- read.csv("~/Desktop/UPAR ESSAS COISAS AQUI/trabic2/trabVCompMov/QuickSort.txt", sep=";")
Insercao = Insercao[,-4]
Selecao = Selecao[,-4]
HeapSort = HeapSort[,-4]
QuickSort = QuickSort[,-4]
codigosPorMes <- read.table("~/Desktop/UPAR ESSAS COISAS AQUI/trabic2/trabVCompMov/codigosPorMes", quote="\"", comment.char="")
colnames(codigosPorMes) = c("NumCodigos")
Insercao = cbind(Insercao[,], codigosPorMes)
Selecao = cbind(Selecao[,], codigosPorMes)
HeapSort = cbind(HeapSort[,], codigosPorMes)
QuickSort = cbind(QuickSort[,], codigosPorMes)

plot(Insercao[,c(4,2)], type = "line", main = "Inserção Direta", xlab = "Número de Códigos", 
     ylab = "Número de comparações", xlim = c(0,10000), ylim = c(2000,25000000))
plot(Selecao[,c(4,2)], type = "line", main = "Seleção", xlab = "Número de Códigos", 
     ylab = "Número de comparações", xlim = c(0,10000), ylim = c(300,74000))
plot(HeapSort[,c(4,2)], type = "line", main = "HeapSort", xlab = "Número de Códigos", 
     ylab = "Número de comparações", xlim = c(0,10000), ylim = c(500,180000))
plot(QuickSort[,c(4,2)], type = "line", main = "QuickSort", xlab = "Número de Códigos", 
     ylab = "Número de comparações", xlim = c(0,10000), ylim = c(400,100000))
      