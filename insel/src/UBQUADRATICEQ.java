package eu.insel.userblock;

import de.vseit.network.Attribute;
import de.vseit.network.schema.Icon;
import de.vseit.network.schema.StringType;
import eu.insel.block.Block;
import eu.insel.block.BlockInfo;

@Icon(path="icons/ubcpp.png")

@BlockInfo(function="ub0016",
   group  = 3,
   inMin  = 1,
   inMax  = 1,
   inIni  = 1,
   outMin = 0,
   outMax = 3,
   outIni = 0,
   bpMin  = 2,
   bpMax  = 2,
   spMin  = 0,
   spMax  = 0)

public final class UBQUADRATICEQ extends Block <UBQUADRATICEQ>
{
	public @StringType(init="0") Attribute<String> bp1;
	public @StringType(init="0") Attribute<String> bp2;

   public UBQUADRATICEQ(){}
}

