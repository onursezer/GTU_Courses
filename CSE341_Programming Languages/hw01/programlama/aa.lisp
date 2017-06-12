(defun intersect  (list1 list2)
	(if (eq list1 ())
    	list1
    	(if (mymember (car list1) list2)
        	;(cons (car list1) (intersect (cdr list1) list2))
            ;(intersect (cdr list1) list2)
            "yes"
        )
    ) 
)
(defun mymember (clist1 list2)
	(if (and (listp clist1) (listp (car list2)) (eq (mylength clist1) (mylength (car list2))))
		(if (= (control clist1 (car list2)) (mylength clist1))
			t
			nil
		)	
		nil
	)
)
(defun mylength(list1)
	(if(eq (cdr list1) nil)
		1
		(+ 1 (mylength (cdr list1)))
	)
)
(defun control (list1 list2)
	(if (eq list1 ())
    	0
    	(if (member (car list1) list2)
        	(+ 1 (control (cdr list1) list2))
        	0
        )
    ) 
)