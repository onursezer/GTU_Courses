(defun intersect  (list1 list2)
	(if (eq list1 ())
    	list1
      	(if (member (car list1) list2)
        	(cons (car list1) (intersect (cdr list1) list2))
            (intersect (cdr list1) list2)
        )
    )
)