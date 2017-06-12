;;; Onur SEZER
;;; 121044074

(defun intersect  (list1 list2) 
	(if (eq list1 ()) ;;; list1 nil olana kadar devam eden recursion'in kosulu
    	list1
    	(if (mymember (car list1) list2)
        	(cons (car list1) (intersect (cdr list1) list2)) ;;; mymember true ise calisir
            (intersect (cdr list1) list2) ;;; mymember nil ise calisir
        )
    ) 
)
(defun mymember (list1 list2) ;;; nestedListControl fonksiyonunu cagirir, nested list yoksa list1'in list2 icinde olup olmamasina bakar
	(if (nestedListControl list1 list2)
		t	
		(if (member list1 list2) ;;; nested list yoksa intersect fonksiyonundan gelen car list1'in list2' nin elemani olup olmadigini kontrol eder 
			t
			nil
		)
	)
)
(defun nestedListControl (list1 list2) ;;; nested list kontrolu yapar
	(if (eq list2 ()) ;;; list2 nil olana kadar devam eden recursion' in kosulu
		nil
		;;; list1 ve list2 nin liste olup olmadigini kontrol eder, liste ise uzunluklari esit mi diye kontrol eder
		(if (and (listp list1) (listp (car list2)) (eq (mylength list1) (mylength (car list2))))
			;;; listelerin elamanlari birbiriyle aynı mi diye kontrol eder
			(if (= (control list1 (car list2)) (mylength list1))
				t
				(nestedListControl list1 (cdr list2))
			)
			(nestedListControl list1 (cdr list2)) 
		)
	)
)
(defun mylength(list1) ;;; liste uzunlugunu bulur
	(if (eq (cdr list1) nil)
		1
		(+ 1 (mylength (cdr list1))) 
	)
)
(defun control (list1 list2) ;;; list1 elemanlarinin list2 icinde kac tane oldugunu bulur
	(if (eq list1 ()) ;;; list1 nill ise recursion biter 
    	0
    	(if (member (car list1) list2) ;;; (car list1) list2 icinde varsa recursiona devam eder
        	(+ 1 (control (cdr list1) list2)) ;;; icinde varsa 1 ile toplayarak recursiona devam eder
        	0 ;;; yoksa recursion biter
        )
    ) 
)
