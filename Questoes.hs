-- Questão 1 --
-- Merge de Dicionário em Haskell --

 data Dict k v = Dict [(k,v)] deriving (Show)

apply:: Eq a => Dict a b -> a -> Maybe b
apply (Dict []) nk = Nothing
apply (Dict ((k,v):ps)) nk
 |k == nk = Just v
 |otherwise = apply (Dict ps) nk

instance Functor (Dict a) where
    fmap f (Dict ps) = Dict (map (fmap f) ps)

add :: (a,b) -> Dict a b -> Dict a b
add entry (Dict ps) = Dict (entry:ps)

delete :: Eq t => Dict t v -> t -> Dict t v
delete (Dict []) _ = Dict [] 
delete (Dict ((k,v):ps)) nk | nk == k = Dict ps 
                            | otherwise = add (k,v) (delete (Dict ps) nk)

findInDict :: Eq a => Dict a b -> a -> Bool
findInDict (Dict []) _ = False
findInDict (Dict ((k,v):ps)) nk | nk == k = True
                                | otherwise = False

add' ::Eq a => (a,b) -> Dict a b -> Dict a b
add' (x,y) (Dict []) = Dict [(x,y)]
add' (x,y) (Dict ((k,v):ps)) | x == k = Dict ((x,y):ps)
                             | otherwise = add (k,v) (add' (x,y) (Dict ps))

mergeDict :: Eq a => Dict a b -> Dict a b -> Dict a b
mergeDict (Dict []) (Dict ps) = Dict ps
mergeDict (Dict ps) (Dict []) = Dict ps
mergeDict (Dict xs) (Dict ((k,v):ps)) | findInDict (Dict xs) k == False = add (k,v) (mergeDict (Dict xs) (Dict ps))
                                      | otherwise = mergeDict (add' (k,v) (Dict xs)) (Dict ps) 

-- add' (k,v) Dict (xs) : mergeDict (Dict (xs)) (Dict ps) 


--toList (Dict [(k,v)]) = []
--toList (Dict ((k,v):ps)) = (k,v) : toList Dict ps
--fazer merge de dicionarios

-- mergeDict (Dict [(1,2), (2,1)]) (Dict [(1,3),(3,4)])
