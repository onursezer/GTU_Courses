(defun garde-o (list1 list2)
	(cond ((not list1) nil)
  		((equal (car list1) list2) (cons (car list1) (garde-o (cdr list1) list2)))
  		((garde-o (cdr list1) list2))
	)
)
(defun foo(list1 list2)
	(if (eq (length list1) (length (car list2)))
		"yes"
		"no"
	)

)
(defun foo2(list1 list2)

	(if(listp list1)
		"yes"
		"no"
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
(defun nestedListControl (list1 list2)
	(if (eq list2 ())
		nil
		(if (and (listp list1) (listp (car list2)) (eq (mylength list1) (mylength (car list2))))
			(if (= (control list1 (car list2)) (mylength list1))
				t
				(nestedListControl list1 (cdr list2))
			)
			(nestedListControl list1 (cdr list2))
		)
	)
)