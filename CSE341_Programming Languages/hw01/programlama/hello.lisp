(defun intersect  (list1 list2)
	(if (eq list1 ())
    	list1
      	(if (member (car list1) list2)
        	(cons (car list1) (intersect (cdr list1) list2))
            (intersect (cdr list1) list2)
        )
    )
)
(defun  mymember (list1 list2) 
	(if (eq list2 ())
    	list2
    	(if (equalp(list1 (car list2)))
    		t
    		(mymember list1 (cdr list2))
    	)
    )	
)


(defun mymember2 (liste)
	(cond ((not list2) nil)
  		((equal list1 (car list2)) t)
  		((mymember2 (cdr list2)))
	)
) 