(module "Cherry aligner" (layer F.Cu) (tedit 5D993F00)
  (fp_text reference "REF**" (at -3.81 -6.858) (layer F.SilkS)
    (effects (font (size 1 1) (thickness 0.15)))
  )
  (fp_text value "Cherry aligner" (at -0.508 6.985) (layer B.Fab)
    (effects (font (size 1 1) (thickness 0.15)))
  )
  (fp_line (start -5.715 -5.715) (end -5.715 5.715) (layer Edge.Cuts) (width 0.12))
  (fp_line (start 5.715 5.715) (end 5.715 -5.715) (layer Edge.Cuts) (width 0.12))
  (fp_line (start -5.715 -5.715) (end 5.715 -5.715) (layer Edge.Cuts) (width 0.12))
  (fp_line (start -5.715 5.715) (end 5.715 5.715) (layer Edge.Cuts) (width 0.12))
)